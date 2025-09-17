const http = require("http");
const { handleRequests, handleCalculation } = require("./routes")
const server = http.createServer((req, res) => {
  handleRequests(req, res);
  handleCalculation(req, res);
});

const PORT = 5000;
server.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});