import React from "react";
import ReactDOM from "react-dom/client";
import {useState, useEffect} from "react";




export const ListItem = ({Name, Date, State}) => {

    const [taskName, setTaskName] = useState(Name||"Math Assigment");
    const [taskDate, setTaskDate] = useState(Date||"Today");
    const [taskState, setTaskState] = useState(State||"Incomplete");

    return (
        <li>
            <div className="list-item">
                <div className="TaskName">
                    {taskName}
                </div>
                <div className="TaskDate">
                    {taskDate}
                </div>
                <div className="TaskStatus">
                    {taskState}
                </div>
                <div className="TaskUsers">
                    <img src="https://fatcatart.com/wp-content/uploads/2012/01/Leonardo_Mona_Lisa_cat_sm.jpg"></img>
                    <img src="https://i.pinimg.com/originals/83/1d/96/831d961e046efe735d7e05be1832e6b1.jpg"></img>
                    <img src="https://www.artmajeur.com/medias/standard/i/s/isabelle-wickihalder/artwork/13325582_img-20200524-wa0012.jpg"></img>
                    <img src="https://arc-anglerfish-arc2-prod-infobae.s3.amazonaws.com/public/QXQ236DQORFGZJOZYIDTBVNMP4.jpg"></img>
                </div>
            </div>
        </li>
    )
};

