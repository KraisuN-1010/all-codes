//Core Modules
const path = require('path');

//External Modules
const express = require('express');

const userRouter = express.Router();

userRouter.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, "../", "views", "home.html"));
});

module.exports = userRouter;