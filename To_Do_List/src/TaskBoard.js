import ReactDOM from "react-dom/client";
import React from "react";
import {ListItem} from "./ListItem";

export const TaskBoard = ()=>{
    let tasks = [];
    for(let i = 0; i < 20; i++){
        tasks.push(<ListItem/>)
    }
    return (
        <div className="task-board">
            <div className="task-header">
                <h1>To Do List</h1>
            </div>
            <div className="task-tittle">
                <div className="TaskName">
                    <a href="#">Task ▼</a>
                </div>
                <div className="TaskDate">
                    <a href="#">Deadline ▼</a>
                </div>
                <div className="TaskStatus">
                    <a href="#">Status </a>
                </div>
                <div className="TaskUsers">
                    <a href="#">Users</a>
                </div>
            </div>
            <div className="list-item" id="Head">
                <div className="TaskName">
                    <a href="#">Add new task</a>
                </div>

            </div>
            <ul>
                {tasks}

            </ul>
        </div>
    )
}