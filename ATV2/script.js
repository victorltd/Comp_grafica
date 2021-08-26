function dda(x0, y0, x1, y1)
{
    const dx = x1 - x0,
          dy = y1 - y0,
          s  = Math.abs(dx) > Math.abs(dy) ? Math.abs(dx) : Math.abs(dy),
          xi = dx * 1.0 / s,
          yi = dy * 1.0 / s
 
    var x  = x0,
        y  = y0,
        out= [],
		vecX = [],
		vecY = []

	var auxX, auxY;
 
    out.push({x: x0, y: y0});
    //DrawPixel(x0,y0);
	vecX.push(x0);
	vecY.push(y0);
	
 
    for (var i = 0; i < s; i++) {
        x += xi;
        y += yi;
        var xx = Math.round(x);
		var yy = Math.round(y);
        out.push({x: x, y: y});
		vecX.push(xx);
		vecY.push(yy);
    DrawPixel(xx,yy);
		
    }

    //return out
	return [vecX, vecY];
}

function bline(x0, y0, x1, y1) {
 
    var dx = Math.abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    var dy = Math.abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
    var err = (dx>dy ? dx : -dy)/2;
    var xx=[],
        yy=[];
    while (true) {
      //setPixel(x0,y0);
        xx.push(x0);
        yy.push(y0);
        DrawPixel(x0,y0);
      if (x0 === x1 && y0 === y1) break;
      var e2 = err;
      if (e2 > -dx) { err -= dy; x0 += sx; }
      if (e2 < dy) { err += dx; y0 += sy; }
    }
    DrawPixel(xx,yy);
      return [xx, yy];

  }

  var DrawCirle = function (x0, y0, radius) {
    var x = radius;
    var y = 0;
    var radiusError = 1 - x;
    
    while (x >= y) {
      DrawPixel(x + x0, y + y0);
      DrawPixel(y + x0, x + y0);
      DrawPixel(-x + x0, y + y0);
      DrawPixel(-y + x0, x + y0);
      DrawPixel(-x + x0, -y + y0);
      DrawPixel(-y + x0, -x + y0);
      DrawPixel(x + x0, -y + y0);
      DrawPixel(y + x0, -x + y0);
      y++;
      
      if (radiusError < 0) {
          radiusError += 2 * y + 1;
      }
      else {
          x--;
          radiusError+= 2 * (y - x + 1);
      }
    }
  }


  function circSimples(x0, y0, raio){
    ctx.beginPath();
    ctx.arc(x0, y0, raio, 0, 2 * Math.PI);
    ctx.stroke();

  }


  function pegaValorNova() {
    var x0 = document.getElementById("x00").value;
    var y0 = document.getElementById("y00").value;
    var raio = document.getElementById("raio").value;
    return [x0, y0, raio];
}



function pegaValor() {
      var x0 = document.getElementById("x0").value;
      var y0 = document.getElementById("y0").value;
      var x1 = document.getElementById("x1").value;
      var y1 = document.getElementById("y1").value;
      return [x0, y0, x1, y1];

      
}


function limparTela(){
  document.location.reload(false);
}

var canvas = document.querySelector('canvas')
var ctx = canvas.getContext('2d');
ctx.fillStyle = 'blue';

var DrawPixel = function (x, y) {
  ctx.fillRect(x, y, 1, 1);
}



function clicou1() {
/*
var x0= parseInt(pegaX0());
var y0 = parseInt(pegaY0());
var x1 = parseInt(pegaX1());
var y1 = parseInt(pegaY1());


   */





var x0 = parseInt(pegaValor()[0]);
var y0 = parseInt(pegaValor()[1]);
var x1 = parseInt(pegaValor()[2]);
var y1 = parseInt(pegaValor()[3]);


console.log(x0);
console.log(y0);
console.log(x1);
console.log(y1);

 dda( x0, y0, x1, y1);

aux2 = bline(x0, y0, x1, y1);

// console.log(pegaX0());
// console.log(pegaY0());
// console.log(pegaX1());
// console.log(pegaY1());

//aux = dda( 25, 50, 25, 75);

var auxX= [], auxY = [];
var auxX2= [], auxY2 = [];

//auxX = aux[0];
//auxY = aux[1];

console.log(aux[0]);
console.log(aux[1]);

  }

  function clicou2() {
    /*
    var x0= parseInt(pegaX0());
    var y0 = parseInt(pegaY0());
    var x1 = parseInt(pegaX1());
    var y1 = parseInt(pegaY1());
    
    
       */
    
    
    
    
    
    var x0 = parseInt(pegaValor()[0]);
    var y0 = parseInt(pegaValor()[1]);
    var x1 = parseInt(pegaValor()[2]);
    var y1 = parseInt(pegaValor()[3]);
    
    
    console.log(x0);
    console.log(y0);
    console.log(x1);
    console.log(y1);
    
     
    bline(x0, y0, x1, y1);
    var auxX= [], auxY = [];
    var auxX2= [], auxY2 = [];
    
    
    console.log(aux[0]);
    console.log(aux[1]);
    
    
    
      }


      
function clicou3() {
  /*
  var x0= parseInt(pegaX0());
  var y0 = parseInt(pegaY0());
  var x1 = parseInt(pegaX1());
  var y1 = parseInt(pegaY1());
 */
  var x0 = parseInt(pegaValorNova()[0]);
  var y0 = parseInt(pegaValorNova()[1]);
  var raio = parseInt(pegaValorNova()[2]);
  console.log(x0);
  console.log(y0);
  console.log(raio);
  

  
  DrawCirle( x0, y0, raio);

    }

    function clicou4() {
      /*
      var x0= parseInt(pegaX0());
      var y0 = parseInt(pegaY0());
      var x1 = parseInt(pegaX1());
      var y1 = parseInt(pegaY1());
     */
      var x0 = parseInt(pegaValorNova()[0]);
      var y0 = parseInt(pegaValorNova()[1]);
      var raio = parseInt(pegaValorNova()[2]);
      console.log(x0);
      console.log(y0);
      console.log(raio);
      
    
      
      circSimples( x0, y0, raio);
    
        }