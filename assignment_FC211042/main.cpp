//The output can be rotated using arrow keys

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>


float rotationAngle = 0.0;


// Light position and properties
GLfloat lightPos[] = { -5.0f, 4.0f, 5.0f, 1.0f };
GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };

// Material properties
GLfloat shininess[] = { 50.0f };

void init() {
    glClearColor(0.529, 0.808, 0.922, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set filled polygons mode 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Set up light 0
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);


    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Set default specular material and shininess
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);



}


void drawPlane() {
    glColor3f(0.3, 0.7, 0.3);
    glPushMatrix();
    glBegin(GL_QUADS);

    // Large base land 
    glVertex3f(-4.5, -0.5, -6.5);
    glVertex3f(5.5, -0.5, -6.5);
    glVertex3f(5.5, -0.5, 4.5);
    glVertex3f(-4.5, -0.5, 4.5);

    glEnd();
    glPopMatrix();

    // Small square in the middle
    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
    glBegin(GL_QUADS);

    glVertex3f(-3.5, -0.49, -4.5);
    glVertex3f(3.5, -0.49, -4.5);
    glVertex3f(3.5, -0.49, 4.0);
    glVertex3f(-3.5, -0.49, 3.0);


    glEnd();
    glPopMatrix();

    // front house floor
    glColor3f(00.467, 0.42, 0.353);
    glPushMatrix();
    glTranslatef(-2.0, -0.49, -1.5);
    glScalef(2.5, 0.0005, 5.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //backhouse floor
    glColor3f(00.467, 0.42, 0.353);
    glPushMatrix();
    glTranslatef(1.0, -0.49, -2.0);
    glScalef(3.5, 0.0005, 3.3);
    glutSolidCube(1.0);
    glPopMatrix();

}

void swimmingPool() {

    //left
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(0.0, -0.45, 1.0);
    glScalef(0.1, 0.05, 1.7);
    glutSolidCube(1.0);
    glPopMatrix();

    //Right
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(2.5, -0.45, 1.0);
    glScalef(0.1, 0.05, 1.7);
    glutSolidCube(1.0);
    glPopMatrix();

    //front line
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(1.25, -0.45, 1.8);
    glScalef(2.5, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    //back line
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(1.25, -0.45, 0.2);
    glScalef(2.5, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();


    //water
    glColor4f(0.1, 0.9, 0.9,0.5);
    glColor4f(0.1, 0.9, 0.9, 0.8);
    glPushMatrix();
    glTranslatef(1.25, -0.45, 1);
    glScalef(2.4, -0.05, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();



}

void drawFrontHouse() {

    // Main house body (brown)
    glColor3f(0.408, 0.29, 0.184);
    glPushMatrix();
    glTranslatef(-2.0, 0.0, -1.5);
    glScalef(2.0, 1.0, 3.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // front door outline 
    glColor3f(0.239, 0.141, 0.059);
    glPushMatrix();
    glTranslatef(-2.5, -0.125, 0.0);
    glScalef(0.58, 0.85, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    // front door 1 
    glColor3f(0.588, 0.384, 0.094);
    glPushMatrix();
    glTranslatef(-2.5, -0.1, 0.005);
    glScalef(0.5, 0.8, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    //door lock sphere
    glPushMatrix();
    glTranslatef(-2.3, -0.1, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();

    // Middle part
    glColor3f(0.776, 0.686, 0.552);
    glPushMatrix();
    glTranslatef(-2.0, 0.6, -1.5);
    glScalef(2.5, 0.2, 5.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //bridge part
    glColor3f(0.776, 0.686, 0.552);
    glPushMatrix();
    glTranslatef(-0.7, 0.6, -2.0);
    glScalef(0.1, 0.2, 2.3);
    glutSolidCube(1.0);
    glPopMatrix();

}

void drawFrontFirstFloor() {
    // Main house body (orange)
    glColor3f(0.408, 0.29, 0.184);
    glPushMatrix();
    glTranslatef(-2.0, 1.2, -1.5);
    glScalef(2.0, 1.0, 3.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //pot
    glColor3f(0.408, 0.29, 0.184);
    glPushMatrix();
    glTranslatef(-2.8, 0.75, 0.7);
    glScalef(0.2, 0.2, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    //bush
    glPushMatrix();
    glColor3f(0.09, 0.91, 0.114);
    glTranslatef(-2.8, 0.85, 0.7);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // front door outline 
    glColor3f(0.239, 0.141, 0.059);
    glPushMatrix();
    glTranslatef(-1.5, 1.125, 0.0);
    glScalef(0.58, 0.85, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();


    // front door 1 
    glColor3f(0.588, 0.384, 0.094);
    glPushMatrix();
    glTranslatef(-1.5, 1.1, 0.0);
    glScalef(0.5, 0.8, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    //door lock
    glPushMatrix();
    glTranslatef(-1.3, 1.1, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();

    // Back window outline
    glColor3f(0.239, 0.141, 0.059);
    glPushMatrix();
    glTranslatef(-2.5, 1.1, -3.0);
    glScalef(0.85, 0.8, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // Back window glass 1
    glColor4f(0.82, 0.949, 0.969, 0.812);
    glPushMatrix();
    glTranslatef(-2.7, 1.075, -3.005);
    glScalef(0.375, 0.75, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // Back window glass 2
    glColor4f(0.82, 0.949, 0.969, 0.812);
    glPushMatrix();
    glTranslatef(-2.3, 1.075, -3.005);
    glScalef(0.375, 0.75, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // Post color (dark brown)
    glColor3f(0.776, 0.686, 0.552);

    // Roof dimensions
    float roofX = -2.0, roofY = 1.8, roofZ = -1.5;
    float halfWidth = 2.5 / 2, halfDepth = 5.0 / 2;
    float postHeight = 1.0;

    // Positions for the 4 corner posts
    float postPositions[4][2] = {
        { roofX - halfWidth + 0.05, roofZ - halfDepth + 0.05 },
        { roofX + halfWidth - 0.05, roofZ - halfDepth + 0.05 },
        { roofX - halfWidth + 0.05, roofZ + halfDepth - 0.05 },
        { roofX + halfWidth - 0.05, roofZ + halfDepth - 0.05 }
    };

    // Draw the 4 posts
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(postPositions[i][0], 1.2, postPositions[i][1]);
        glScalef(0.1, postHeight, 0.1);
        glutSolidCube(1.0);
        glPopMatrix();
    }
    // Top roof (light gray)
    glColor3f(0.776, 0.686, 0.552);
    glPushMatrix();
    glTranslatef(-2.0, 1.8, -1.5);
    glScalef(2.5, 0.2, 5.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawBackHouse() {
    // Back house body 
    glColor3f(0.408, 0.29, 0.184);
    glPushMatrix();
    glTranslatef(1.0, 0.0, -2.0);
    glScalef(3.0, 1.0, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // window1 
    glColor3f(0.239, 0.141, 0.059);
    glPushMatrix();
    glTranslatef(0.5, -0.15, -1.0);
    glScalef(0.9, 0.8, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    //window1 glass 1
    glColor4f(0.82, 0.949, 0.969, 0.812);
    glPushMatrix();
    glTranslatef(0.275, -0.15, -0.95);
    glScalef(0.4, 0.7, 0.0005);
    glutSolidCube(1.0);
    glPopMatrix();

    //window1 glass2
    glPushMatrix();
    glColor4f(0.82, 0.949, 0.969, 0.812);
    glTranslatef(0.725, -0.15, -0.95);
    glScalef(0.4, 0.7, 0.0005);
    glutSolidCube(1.0);
    glPopMatrix();

    // window2
    glColor3f(0.239, 0.141, 0.059);
    glPushMatrix();
    glTranslatef(1.8, -0.15, -1.0);
    glScalef(0.9, 0.8, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    //window2 glass1
    glColor4f(0.82, 0.949, 0.969, 0.812);
    glPushMatrix();
    glTranslatef(1.575, -0.15, -0.95);
    glScalef(0.4, 0.7, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    //window2 glass1
    glColor4f(0.82, 0.949, 0.969, 0.812);
    glPushMatrix();
    glTranslatef(1.575, -0.15, -0.949);
    glScalef(0.4, 0.7, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    //window2 glass2
    glColor4f(0.82, 0.949, 0.969, 0.812);
    glPushMatrix();
    glTranslatef(2.025, -0.15, -0.95);
    glScalef(0.4, 0.7, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    // Roof 
    glColor3f(0.776, 0.686, 0.552);
    glPushMatrix();
    glTranslatef(1.0, 0.6, -2.0);
    glScalef(3.3, 0.2, 2.3);
    glutSolidCube(1.0);
    glPopMatrix();

    //pot
    glColor3f(0.408, 0.29, 0.184);
    glPushMatrix();
    glTranslatef(2.5, 0.75, -2.0);
    glScalef(0.2, 0.2, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    //bush
    glPushMatrix();
    glColor3f(0.09, 0.91, 0.114);
    glTranslatef(2.5, 0.85, -2.0);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    //posts
    glColor3f(0.776, 0.686, 0.552);

    float roofX = 1.0, roofY = 0.6, roofZ = -2.0;
    float halfWidth = 3.3 / 2, halfDepth = 2.3 / 2;
    float postHeight = 1.0;

    // Positions for the 4 corner posts
    float postPositions[4][2] = {
        { roofX - halfWidth + 0.05, roofZ - halfDepth + 0.05 },
        { roofX + halfWidth - 0.05, roofZ - halfDepth + 0.05 },
        { roofX - halfWidth + 0.05, roofZ + halfDepth - 0.05 },
        { roofX + halfWidth - 0.05, roofZ + halfDepth - 0.05 }
    };

    //  4 posts
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(postPositions[i][0], 0.0, postPositions[i][1]);
        glScalef(0.1, postHeight, 0.1);
        glutSolidCube(1.0);
        glPopMatrix();
    }



}
void drawFence() {
    // protection fence (transparent)
    //front
    glDepthMask(GL_FALSE);
    glColor4f(0.1, 0.3, 0.3, 0.2);

    //front
    glPushMatrix();
    glTranslatef(0.95, 0.85, -0.85);
    glScalef(3.4, 0.3, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    //back
    glPushMatrix();
    glTranslatef(0.95, 0.85, -3.15);
    glScalef(3.4, 0.3, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    //side
    glPushMatrix();
    glTranslatef(2.65, 0.85, -2.00);
    glScalef(0.005, 0.3, 2.3);
    glutSolidCube(1.0);
    glPopMatrix();

    //front house side fence

    glPushMatrix();
    glTranslatef(-3.25, 0.85, -1.5);
    glScalef(0.005, 0.3, 4.8);
    glutSolidCube(1.0);
    glPopMatrix();

    //front house front side fence
    glPushMatrix();
    glTranslatef(-2.325, 0.85, 1.0);
    glScalef(1.65, 0.3, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    //front house back side fence
    glPushMatrix();
    glTranslatef(-2.0, 0.85, -4.0);
    glScalef(2.3, 0.3, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();

    //front house front side fence 1
    glPushMatrix();
    glTranslatef(-0.75, 0.85, 0.025);
    glScalef(0.005, 0.3, 1.75);
    glutSolidCube(1.0);
    glPopMatrix();

    //front house front side fence 2
    glPushMatrix();
    glTranslatef(-0.75, 0.85, -3.525);
    glScalef(0.005, 0.3, 0.75);
    glutSolidCube(1.0);
    glPopMatrix();

    glDepthMask(GL_TRUE);
}

void stairCase() {
    glDepthMask(GL_FALSE);
    glColor4f(0.1, 0.3, 0.3, 0.2);
    glPushMatrix();
    glBegin(GL_QUADS);

    // left fence part
    glVertex3f(-1.5, -0.1, 2.5);
    glVertex3f(-1.5, -0.5, 2.5);
    glVertex3f(-1.5, 0.7, 1.0);
    glVertex3f(-1.5, 1.1, 1.0);

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_QUADS);

    //Right fence part
    glVertex3f(-0.85, -0.1, 2.5);
    glVertex3f(-0.85, -0.5, 2.5);
    glVertex3f(-0.85, 0.7, 1.0);
    glVertex3f(-0.85, 1.1, 1.0);

    glEnd();
    glPopMatrix();
    glDepthMask(GL_TRUE);

    glColor3f(0.1, 0.3, 0.3);

    // left fence
    glBegin(GL_QUADS);
    glVertex3f(-1.5, -0.45, 2.5);
    glVertex3f(-1.5, -0.5, 2.5);
    glVertex3f(-1.5, 0.7, 1.0);
    glVertex3f(-1.5, 0.75, 1.0);
    glEnd();

    // right fence
    glBegin(GL_QUADS);
    glVertex3f(-0.85, -0.45, 2.5);
    glVertex3f(-0.85, -0.5, 2.5);
    glVertex3f(-0.85, 0.7, 1.0);
    glVertex3f(-0.85, 0.75, 1.0);
    glEnd();

    //steps
    glColor3f(0.1, 0.3, 0.3);
    glPushMatrix();
    glTranslatef(-1.175, 0.7, 1.375);
    glScalef(0.65, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    //extra
    glPushMatrix();
    glTranslatef(-1.175, 0.5, 1.5625);
    glScalef(0.65, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.175, 0.3, 1.75);
    glScalef(0.65, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    //extra
    glPushMatrix();
    glTranslatef(-1.175, 0.115, 1.9375);
    glScalef(0.65, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.175, -0.07, 2.125);
    glScalef(0.65, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    //extra
    glPushMatrix();
    glTranslatef(-1.175, -0.228, 2.35);
    glScalef(0.65, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 1.5, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    // Apply rotation to the entire house
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);

    drawPlane();
    swimmingPool();
    drawFrontHouse();
    drawFrontFirstFloor();
    drawBackHouse();
    drawFence();
    stairCase();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
}

// Keyboard input handling
void handleSpecialKeypress(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        rotationAngle -= 5.0;
        break;
    case GLUT_KEY_RIGHT:
        rotationAngle += 5.0;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL House with Rotation");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(handleSpecialKeypress);
    glutMainLoop();
    return 0;
}





