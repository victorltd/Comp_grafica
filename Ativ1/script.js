d3.csv("https://raw.githubusercontent.com/victorltd/Comp_grafica/main/juntos.csv", function(err, rows){

  function unpack(rows, key) {
  return rows.map(function(row) { return row[key]; });
}


var trace1 = {
  type: "scatter",
  mode: "lines",
  name: 'Juazeiro',
  x: unpack(rows, 'date'),
  y: unpack(rows, 'new_deaths_j'),
  line: {color: '#17BECF'}
}

var trace2 = {
  type: "scatter",
  mode: "lines",
  name: 'Petrolina',
  x: unpack(rows, 'date'),
  y: unpack(rows, 'new_deaths_p'),
  line: {color: '#7F7F7F'}
}

var data = [trace1,trace2];

var layout = {
  title: 'Mortes por Covid-19',
};

Plotly.newPlot('myDiv', data, layout);
})