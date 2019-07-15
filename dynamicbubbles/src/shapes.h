//
//  shapes.h
//  bubbles
//
//  Created by sabelle on 5/1/19.
//

#ifndef shapes_h
#define shapes_h

//#include <vector>
#include "ofMain.h"
#include "ofxBox2d.h"
#include "b2Settings.h"
//#undef b2_maxPolygonVertices
//#define b2_maxPolygonVertices 10
#endif /* shapes_h */


class bubble : public ofxBox2dCircle {
public:
    void draw() {
        float radius = getRadius();
        glPushMatrix();
        glTranslatef(getPosition().x, getPosition().y, 0);
        ofDrawCircle(0, 0, radius);
        glPopMatrix();
    }
};


/////////////////////////////////////////////

class star: public ofxBox2dBaseShape {
private:
    
    
public:
    void setup(b2World * b2dworld, float x, float y) {
        if (b2dworld == NULL) {
            ofLog(OF_LOG_NOTICE, "ofxBox2dCircle :: setup : - must have a valid world -");
            return;
        }
        //https://stackoverflow.com/questions/4361420/how-to-create-a-static-body-with-b2polygonshape-vertices
        b2PolygonShape shape;
        const b2Vec2 starVertices[] = {
            b2Vec2( 0.00,  2.01),
            b2Vec2(-0.58,  0.81),
            b2Vec2(-1.91, -0.62),
            b2Vec2(-0.91, -0.14),
            b2Vec2(-1.18, -1.63),
            b2Vec2( 0.00, -0.83),
            b2Vec2( 1.18, -1.63),
            b2Vec2( 0.91, -0.14),
            b2Vec2( 1.91,  0.62),
            b2Vec2( 0.58,  0.81)
            //            b2Vec2( 0.00,  8.04),
            //            b2Vec2(-1.74,  2.43),
            //            b2Vec2(-7.64,  2.48),
            //            b2Vec2(-2.73, -0.42),
            //            b2Vec2(-4.72, -6.52),
            //            b2Vec2( 0.00, -2.49),
            //            b2Vec2( 4.72, -6.52),
            //            b2Vec2( 2.73, -0.42),
            //            b2Vec2( 7.64,  2.48),
            //            b2Vec2( 1.74,  2.43)
        };
        shape.Set(starVertices, 10);
        
        fixture.shape = &shape;
        fixture.density = density;
        fixture.friction = friction;
        fixture.restitution = bounce;
        
        if (density == 0.f) bodyDef.type = b2_staticBody;
        else bodyDef.type = b2_dynamicBody;
        
        bodyDef.position.Set(x/OFX_BOX2D_SCALE, y/OFX_BOX2D_SCALE);
        
        body  = b2dworld->CreateBody(&bodyDef);
        body->CreateFixture(&fixture);
        
        alive = true;
    }
    
    //http://www.iforce2d.net/b2dtut/drawing-objects
    void render() {
        glColor3f(224, 186, 242);
        ofSetHexColor(0xe0baf2);
        //
        //        glBegin(GL_LINES);
        //        glVertex2f( 0.00,  2.01);
        //        glVertex2f( 0.58,  0.81);
        //        glVertex2f( 1.91,  0.62);
        //        glVertex2f( 0.91, -0.14);
        //        glVertex2f( 1.18, -1.63);
        //        glVertex2f( 0.00, -0.83);
        //        glVertex2f(-1.18, -1.63);
        //        glVertex2f(-0.91, -0.14);
        //        glVertex2f(-1.91, -0.62);
        //        glVertex2f(-0.58,  0.81);
        //        glEnd();
    }
    
    void draw() {
        ofSetHexColor(0xe0baf2);
        glPushMatrix();
        glTranslatef(getPosition().x, getPosition().y, 0);
        ofRotateDeg(getRotation());
        ofSetHexColor(0xe0baf2);
        //render();
        glPopMatrix();
    }
};

