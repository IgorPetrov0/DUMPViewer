#version 330 core
     in vec2 tC;
     uniform sampler2D tex;
     out vec4 color;

     void main(void)
     {
         color=texture2D(tex,tC);
         //color=texture(tex,tC);
     }
