#include <server.h>
#include <TicTacToe.h>

using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

    TicTacToe game;

    server.renderHTML("/", "index.html");

    // This endpoint initializes the tic tac toe board
    server.route("/init", [&](const request& req, response& res){
            // Clear the game board
            game.resetBoard();
            ucm::json board = game.getBoard();

            res.sendJSON(board); 
    });

    server.route("/reset", [&](const request& req, response& res){
        // Clear the game board

        game.resetBoard();
        ucm::json board = game.getBoard();

        res.sendJSON(board); 
    });

    server.route("/test", [&](const request& req, response& res){
        // Clear the game board

        game.testBoard();

        ucm::json board = game.getBoard();

        res.sendJSON(board); 
    });    

    server.route("/click", [&](const request& req, response& res){
            if(req.has_params({"x","y"})){
                std::string xS = req.url_params.get("x");
                std::string yS = req.url_params.get("y");
                // convert string to int
                int x = stoi(xS);
                int y = stoi(yS);

                ucm::json ans = game.clicked(x,y);

                game.checkWin();

                res.sendJSON(ans);
            }
            else{
                res.sendError400();
            }
    });
    
    server.route("/message", [&](const request& req, response& res){
        if (req.has_params({})){

            ucm::json ans = game.getMessage();
            
            res.sendJSON(ans);
        }
        else{
            res.sendError400();
        }
    });

    server.run();
}
