const express = require('express');
const path = require('path');

const app = express();
const PORT = 3000;

// Serve everything from public/
app.use(express.static(path.join(__dirname, '..', 'public')));

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "../public/home.html"))
  console.log("Entered in home app")
})

app.get("/about", (req, res) => {
  res.sendFile(path.join(__dirname, "public/about.html"))
  console.log("entered about")
})

app.get("/timzeones", (req, res) => {
  res.sendFile(path.join(__dirname, "timezones.html"))
  console.log("entered timezones")
})

app.listen(PORT, () => {
  console.log(`✨ SamePages server running at http://localhost:${PORT}`);
});