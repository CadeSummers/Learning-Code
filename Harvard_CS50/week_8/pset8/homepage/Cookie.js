let cookies = 0;
let highscore = 0;

function count() {
    cookies++;
    
    document.querySelector('#CookieScore').innerHTML = cookies;
}

/*Not yet working, want to show score held across multiple page*/
function gamescore() {
    
    /*Check if # of cookies clicked is highscore*/
    if (cookies > highscore)
    {
        highscore = cookies;
        
        let score = String(cookies);
    
        localStorage.setItem("score", score);
    }
    
    let old_score = localStorage.getItem("score");
    
    old_score = Number(old_score);
    
    /*Check against previous highscore value that is in localStorage*/
    if (old_score > highscore)
    {
        highscore = old_score;
        
        old_score = String(old_score);
        
        localStorage.setItem("score", old_score);
    }
    
}

function reset() {
    
    cookies = 0;
    
    document.querySelector('#CookieScore').innerHTML = cookies;
}

function end_game() {
    
    gamescore();
    reset();
    
}

function write_table()
{
    
    highscore = localStorage.getItem("score");
    /*window.onload(document.querySelector("#HighScore").innerHTML = highscore)writes highscore and other values to GameStats*/
    document.querySelector("#HighScore").innerHTML = highscore;
}