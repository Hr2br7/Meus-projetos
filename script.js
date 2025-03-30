function converterFah(){
var num1 = window.document.querySelector('input#n1-fahenheit');
var resultado = window.document.querySelector('div#res-0');
var n1 = Number(num1.value);
var conversao = (n1 - 32) * 5/9;

    if(conversao < 0){
    resultado.innerHTML = `<p style="color:blue">${n1} °F são ${conversao} °C</p>`;
    resultado.innerHTML += `<p style="color:blue"> <strong>FRIO!!!(Abaixo da TF da água)</strong> </p>`
    }
    if(conversao >= 0 && conversao < 100){
    resultado.innerHTML = `<p style="color:lightgreen">${n1} °F são ${conversao} °C</p>`;
    resultado.innerHTML += `<p style="color:lightgreen"> <strong>Acima da TF e abaixo da TE da água</strong> </p>`
    }
    if(conversao >= 100){
    resultado.innerHTML = `<p style="color:red">${n1} °F são ${conversao} °C</p>`;
    resultado.innerHTML += `<p style="color:red"> <strong>Acima ou na TF da água</strong> </p>`
    }

}

function converterCel(){
    var num1 = window.document.querySelector('input#n1-celcius');
    var resultado = window.document.querySelector('div#res-1');
    var n1 = Number(num1.value);
    var conversao = (n1 * 9/6) + 32;
    
    if(conversao < 32){
    resultado.innerHTML = `<p style="color:blue">${n1} °F são ${conversao} °C</p>`;
    resultado.innerHTML += `<p style="color:blue"> <strong>FRIO!!!(Abaixo da TF da água)</strong> </p>`
    }
    if(conversao >= 32 && conversao < 212){
    resultado.innerHTML = `<p style="color:lightgreen">${n1} °F são ${conversao} °C</p>`;
    resultado.innerHTML += `<p style="color:lightgreen"> <strong>Acima da TF e abaixo da TE da água</strong> </p>`
    }
    if(conversao >= 212){
    resultado.innerHTML = `<p style="color:red">${n1} °F são ${conversao} °C</p>`;
    resultado.innerHTML += `<p style="color:red"> <strong>Acima ou na TF da água</strong> </p>`
    }
}