//Core Modules
const path = require('path');

//Local Modules
const { rootDir } = require('../utils/pathUtil');

//External Modules
const express = require('express');
const hostRouter = express.Router();
hostRouter.get("/host",(req, res, next) => {
  res.sendFile(path.join(rootDir, "views", "home.html"));
});

hostRouter.get("/host/add-home", (req, res, next) => {
  res.sendFile(path.join(rootDir, "views", "add-home.html"));
});

hostRouter.post("/host/add-home", (req, res, next) => {
  console.log(req.body);
  res.send("Your home was registered succesfuly");
});

module.exports = hostRouter;