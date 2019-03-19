#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    start=false;
    
    //Define the L-system
    system.addVariable("F");
    system.addVariable("A");
    system.addConstant("+");
    system.addConstant("-");
    system.setStart("F");
    
    //modelisation of stem and leaves
    system.addRule(LRule("F", "F[+F[+F]]F[−-F-AF]F"));
    
    //modelisation of bud
    system.addRule(LRule("A", "{[+ff--ff][-ff++ff]}"));
    
    
    depth=5; //here change the size of the plant
    result = system.getLevel(depth);
    strIndex=100;
    
    //set the Turtle
    turtle = Turtle("F", "-", "+");
    turtle.setAngle(25);
    turtle.setLength(5);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(start){ //start on mouse click
       
        if(strIndex<result.size()){
            strIndex+=10; //plant gradually growing
        }
        res=result.substr(0,strIndex);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(start){
        turtle.setColor(ofColor(255,180));
        
        //draw the plant starting from the bottom-left corner
        turtle.draw(res,0,ofGetHeight()+40,-40);
        
    };
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(button==OF_MOUSE_BUTTON_LEFT){
        start=true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
