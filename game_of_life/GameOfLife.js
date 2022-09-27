let cellSize;
let grid;
let canvas;
let pse;

function setup() {
    canvas=createCanvas(600, 600);
    canvas.mouseClicked(XD);
    canvas.parent("CanvasContainer")
    cellSize = 10;
    pse = false;

    grid = Array(Math.floor((height*width)/(cellSize*cellSize)));

    for(let i = 0; i<Math.floor(width/cellSize); i++){
        for(let j = 0; j<Math.floor(height/cellSize); j++){
            let idx = (i+j*Math.floor(width/cellSize));
            grid[idx] = false;
            print(grid[idx]);
        }
    }
}
function mouseClicked(){
    let i = Math.floor(mouseX/cellSize);
    let j = Math.floor(mouseY/cellSize);
    let idx = (i+j*Math.floor(width/cellSize));
    grid[idx] = !grid[idx];
}

function XD(){

}

function keyPressed(){
    pse = !pse;
}

function draw() {
    frameRate(10);
    background(color("rgb(129,129,129)"));
    loadPixels();

    fill(color("rgb(255,255,255)"));

    if(pse){

        let gridCopy = grid.map((x) => x);

        for(let i = 0; i<Math.floor(width/cellSize); i++){
            for(let j = 0; j<Math.floor(height/cellSize); j++){

                let sum = 0;

                sum += gridCopy[((i+1)+(j+1)*Math.floor(width/cellSize))];
                sum += gridCopy[((i-1)+(j+1)*Math.floor(width/cellSize))];

                sum += gridCopy[((i+1)+(j-1)*Math.floor(width/cellSize))];
                sum += gridCopy[((i-1)+(j-1)*Math.floor(width/cellSize))];

                sum += gridCopy[((i+1)+j*Math.floor(width/cellSize))];
                sum += gridCopy[((i-1)+j*Math.floor(width/cellSize))];

                sum += gridCopy[(i+(j+1)*Math.floor(width/cellSize))];
                sum += gridCopy[(i+(j-1)*Math.floor(width/cellSize))];

                if(sum == 3){
                    grid[(i+j*Math.floor(width/cellSize))] = true;
                }
                if(sum > 3 || sum < 2){
                    grid[(i+j*Math.floor(width/cellSize))] = false;
                }
                if(sum == undefined){
                    print(sum)
                }



            }
        }
    }
    for(let i = 0; i<Math.floor(width/cellSize); i++){
        for(let j = 0; j<Math.floor(height/cellSize); j++){


            let pix = (i+j*Math.floor(width/cellSize));



            if(grid[pix]){
                rect(i*cellSize, j*cellSize, cellSize, cellSize);
            }
        }
    }


}