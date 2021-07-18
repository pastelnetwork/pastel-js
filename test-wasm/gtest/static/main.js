document.addEventListener('DOMContentLoaded', function () {
    Pastel().then(function(Pastel){
        Pastel = Pastel;
        console.log(Pastel.RunAllTests());
    })
});