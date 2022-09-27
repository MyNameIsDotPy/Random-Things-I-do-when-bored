import ReactDOM from "react-dom/client";
import React from "react";
import {useState, useEffect} from "react";


export const Section = ({Tittle})=>{
    const [tittle, setTittle] = useState(Tittle || "Tittle")
    let indexes = ["Work", "Home", "YOLO Project"]
    let tittles = []
    for (let i = 0; i<indexes.length; i++){
        tittles.push(<li>
            <h1>
            {indexes[i]}
            </h1>
        </li>)
    }

    return (
        <div className="section">
            <div className="section-header">
                <h1>{tittle}</h1>
            </div>
            <ul>
                {tittles}
            </ul>
        </div>
    )
};