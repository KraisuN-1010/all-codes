// app.js
const http = require('http');
const { handleUserRequest } = require('./user');

const server = http.createServer((req, res) => {
    handleUserRequest(req, res);
});

const PORT = 3000;
server.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
