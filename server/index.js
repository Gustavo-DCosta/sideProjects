const express = require('express');
const path = require('path');

const app = express();
const PORT = 3000;

// Serve everything from public/
app.use(express.static(path.join(__dirname, '..', 'public')));

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "../public/home.html"))
  res.send("Entered in home app")
})

app.get("/about", (req, res) => {
  res.sendFile(path.join(__dirname, "public/about.html"))
  res.send("entered about")
})

app.get("/timzeones", (req, res) => {
  res.sendFile(path.join(__dirname, "timezones.html"))
  res.send("entered timezones")
})

app.get("/api/timezones", (req, res) => {

})

app.listen(PORT, () => {
  console.log(`✨ SamePages server running at http://localhost:${PORT}`);
});