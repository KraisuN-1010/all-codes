//Core Modules
const path = require('path');

//External Modules
const express = require('express');
const hostRouter = express.Router();
hostRouter.get("/host",(req, res, next) => {
  res.sendFile(path.join(__dirname, "../", "views", "home.html"));
});

hostRouter.get("/host/add-home", (req, res, next) => {
  res.sendFile(path.join(__dirname, "../", "views", "add-home.html"));
});

hostRouter.post("/host/add-home", (req, res, next) => {
  console.log(req.body);
  res.send("Your home was registered succesfuly");
});

module.exports = hostRouter;