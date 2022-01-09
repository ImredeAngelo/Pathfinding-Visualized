#version 330 core

//uniform vec4 u_Color;

in vec4 v_Color;

void main(){
	gl_FragColor = v_Color;
}