d3.csv("https://raw.githubusercontent.com/victorltd/Comp_grafica/main/juntos.csv", function(err, rows){

  function unpack(rows, key) {
  return rows.map(function(row) { return row[key]; });
}


var trace1 = {
  type: "scatter",
  mode: "lines",
  name: 'Juazeiro',
  x: unpack(rows, 'date'),
  y: unpack(rows, 'new_confirmed_j'),
  line: {color: '5a189a'}
}

var trace2 = {
  type: "scatter",
  mode: "lines",
  name: 'Petrolina',
  x: unpack(rows, 'date'),
  y: unpack(rows, 'new_confirmed_p'),
  line: {color: 'ff9100'}
}

var data = [trace1,trace2];

var layout = {
  title: 'Casos de Covid-19',
};

Plotly.newPlot('myDiv2', data, layout);
})