import React from "react";
import ReactDOM from "react-dom/client";

import {Section} from "./Section";

export const SectionContainer = ()=>{
    let Tittles = ["Projects", "Pending"]
    let sections = []
    for(let i = 0; i<2; i++){
        sections.push(<Section Tittle={Tittles[i]}/>)
    }
    return (
        <div className="sections-container">
            {sections}
        </div>
    );
};