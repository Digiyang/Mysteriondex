function background_red() {
    document.body.style.backgroundColor = "red";
}
function background_yellow() {
    document.body.style.backgroundColor = "yellow";
}
function background_blue() {
    document.body.style.backgroundColor = "blue";
}
function alert_message() {
    let bg = window.document.body.style.backgroundColor
    if (bg.length === 0){
        let message1 = "Default Background's color is White";
        window.alert(message1);
    }
    else{
        let message2 = "The background's color is ";    
        window.alert(message2 + bg);
    }
}    