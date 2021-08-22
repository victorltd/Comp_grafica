var xValue = ['1º Dose', '2º Dose', 'Dose Única'];

var yValue = [67.82, 25.22, 1.59];
var yValue2 = [68.67, 28.8, 1.01];

var trace1 = {
  x: xValue,
  y: yValue,
  type: 'bar',
  text: yValue.map(String),
  name: 'Juazeiro',
  textposition: 'auto',
  hoverinfo: 'none',
  opacity: 0.5,
  marker: {
    color: 'rgb(20, 54, 66)',
    line: {
      color: 'rgb(168, 32, 26)',
      width: 1.5
    }
  }
};

var trace2 = {
  x: xValue,
  y: yValue2,
  type: 'bar',
  text: yValue2.map(String),
  name: 'Petrolina',
  textposition: 'auto',
  hoverinfo: 'none',
  marker: {
    color: 'rgb(236, 154, 41)',
    line: {
      color: 'rgb(15, 139, 141)',
      width: 1.5
    }
  }
};

var data = [trace1,trace2];

var layout = {
  title: 'Vacinação Percentual'
};

Plotly.newPlot('myDiv3', data, layout);