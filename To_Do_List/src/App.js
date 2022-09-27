import logo from './logo.svg';


import "./index.css";


//const db = require("./db.js");

//console.log(db.query("SELECT * FROM Tasks"))

import {SectionContainer} from "./SectionContainer";
import {TaskBoard} from "./TaskBoard";
function App() {
  return (
    <div className="App">
      <div className="left-container">

        <SectionContainer/>
      </div>
      <div className="right-container">

        <div className="tabs">
          <a href="#">Home</a>
          <a href="#">Tasks</a>
          <a href="#">Meetings</a>
        </div>
        <TaskBoard/>

      </div>

    </div>
  );
}

export default App;
