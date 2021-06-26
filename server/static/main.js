document.addEventListener('DOMContentLoaded', function () {
    Pastel().then(function(Pastel){
        Pastel = Pastel;
        Pastel.test();

        for (let i = 0; i < 10; i++)
            console.log(Pastel.getRandomValue());
    })
});