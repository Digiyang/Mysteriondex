var currentfield = 0 ; 
function check() {
    var x = document.forms;
    var y = x[currentfield].getElementsByTagName("input");
    for(var i = 0 ; i < y.length ; i++) {
        if(y[i].value == ""){
            alert("Please fill required fields");
        }
    }
}