// Called when the html page is refreshed
$(document).ready(function(){
    // Initializing the board when refreshed
    $.get("/init", {}, function(response){
        var data = JSON.parse(response);
        var board = data["board"];
        board = updateBoard(board);
        $("#00").html(board[0]);
        $("#01").html(board[1]);
        $("#02").html(board[2]);

        $("#10").html(board[3]);
        $("#11").html(board[4]);
        $("#12").html(board[5]);

        $("#20").html(board[6]);
        $("#21").html(board[7]);
        $("#22").html(board[8]);

    });
// Clicking the board
    $("#00").click(function(){
        var location = {"x": 0, "y":0};
        $.get("/click", location, function(response){
            console.log("(0, 0) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#00").html(board[0]);
        });
    });
    $("#01").click(function(){
        var location = {"x": 0, "y":1};
        $.get("/click", location, function(response){
            console.log("(0, 1) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#01").html(board[1]);
        });
    });
    $("#02").click(function(){
        var location = {"x": 0, "y":2};
        $.get("/click", location, function(response){
            console.log("(0, 2) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#02").html(board[2]);
        });
    });
    $("#10").click(function(){
        var location = {"x": 1, "y":0};
        $.get("/click", location, function(response){
            console.log("(1, 0) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#10").html(board[3]);
        });
    });
    $("#11").click(function(){
        var location = {"x": 1, "y":1};
        $.get("/click", location, function(response){
            console.log("(1, 1) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#11").html(board[4]);
        });
    });
    $("#12").click(function(){
        var location = {"x": 1, "y":2};
        $.get("/click", location, function(response){
            console.log("(1, 2) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#12").html(board[5]);
        });
    });
    $("#20").click(function(){
        var location = {"x": 2, "y":0};
        $.get("/click", location, function(response){
            console.log("(2, 0) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#20").html(board[6]);
        });
    });
    $("#21").click(function(){
        var location = {"x": 2, "y":1};
        $.get("/click", location, function(response){
            console.log("(2, 1) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#21").html(board[7]);
        });
    });
    $("#22").click(function(){
        var location = {"x": 2, "y":2};
        $.get("/click", location, function(response){
            console.log("(2, 2) was clicked");
            var data = JSON.parse(response);
            var board = data["board"];
            // alert("(0, 0) was clicked");
            board = updateBoard(board);
            updateMessage();
            $("#22").html(board[8]);
        });
    });
    // Button to reset the game board
    $("#resetBtn").click(function(){
		$.get("/reset", {}, function(response){
            console.log("Gamereseted")
            updateMessage();
            var data = JSON.parse(response);
            var board = data["board"];
            board = updateBoard(board);
            $("#00").html(board[0]);
            $("#01").html(board[1]);
            $("#02").html(board[2]);

            $("#10").html(board[3]);
            $("#11").html(board[4]);
            $("#12").html(board[5]);

            $("#20").html(board[6]);
            $("#21").html(board[7]);
            $("#22").html(board[8]);
		});
    });
    // Test button to fill board
    $("#testBtn").click(function(){
		$.get("/test", {}, function(response){
            console.log("test")
            var data = JSON.parse(response);
            var board = data["board"];
            board[4] = 2;
            board = updateBoard(board);
            $("#00").html(board[0]);
            $("#01").html(board[1]);
            $("#02").html(board[2]);

            $("#10").html(board[3]);
            $("#11").html(board[4]);
            $("#12").html(board[5]);

            $("#20").html(board[6]);
            $("#21").html(board[7]);
            $("#22").html(board[8]);
		});
	});
    $.get("/message", {}, function(response){
        // This endpoint serves to display messages
        var data = JSON.parse(response);
        var messageText = data["message"];

        $("#message").html(messageText);
    });
});

// Function to place game tiles
function updateBoard(board) {
    // update Board
    for(var i in board){
        if(board[i] == 1){
            board[i] = '<img src="X.png" style="width:70px; height:70px">';
        }
        else if(board[i] == 2){
            board[i] = '<img src="O.png" style="width:90px; height:90px">';
        }
        else{
            board[i] = '';
        }
    }
    return board; 
  }
  function updateMessage(){
        // Message
        $.get("/message", {}, function(response){
        // This endpoint serves to display messages
        var data = JSON.parse(response);
        var messageText = data["message"];

        $("#message").html(messageText);
    });
  }
