//Core Modules
const path = require('path');

//Local Modules
const { rootDir } = require('../utils/pathUtil');

//External Modules
const express = require('express');

const userRouter = express.Router();

userRouter.get('/', (req, res) => {
  res.sendFile(path.join(rootDir, "views", "home.html"));
});

module.exports = userRouter;