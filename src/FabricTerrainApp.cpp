#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Fabric.h"

#define GRID_SPACING 10;
#define GRID_WIDTH 640;
#define GRID_HEIGHT 480;

using namespace ci;
using namespace ci::app;
using namespace std;

class FabricTerrainApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void repel(Node *tempNode);
    
    static void prepareSettings( Settings *settings );
    
    Fabric mFabric;
    
    int mNumParticles;
    vec3 positions;
    
    int numX,numY;
    int xPadding, yPadding;
    
    float springRL;
    float springDamping;
    float springStiffness;
    float maxSpeed;
};

void FabricTerrainApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 1280,720 );
    settings->setFrameRate( 30.0f );
}

void FabricTerrainApp::setup()
{
    
    gl::clear( Color( 0.15f, 0.15f, 0.15f ) );
    
 
    
    springRL = GRID_SPACING;
    springDamping = 0.5;
    springStiffness = 0.5;
    
    //POSITION THE GRID IN THE CENTER OF THE SCREEN
    
    int num = GRID_WIDTH;
    int den = GRID_SPACING;
    numX = num/den;
    xPadding = (getWindowWidth() - num)/2;
    num = GRID_HEIGHT;
    numY = num/den;
    yPadding = (getWindowHeight() - num)/2;
    
    //CREATE THE GRID OF NODES
    
    for (int x = 0; x < numX; x++) {
        for (int y = 0; y < numY; y++) {
            Node *node = new Node(vec3(x*den, y*den, 0.));
            mFabric.addNode(node);
            if (x == 0 || y == 0 || x == numX-1 || y == numY-1) {
                node->lock();
            }
        }
    }
    
    //CREATE THE SPRINGS
    for (int x = 0; x < numX; x++) {
        for (int y = 0; y < numY; y++) {
            Node *from = new Node(mFabric.nodes.at(x*numY + y)->mLoc);
            if (y < numY-1) {
                Node *down = new Node(mFabric.nodes.at(x*numY + y + 1)->mLoc);
                //cout << down->mLoc << endl;
                Spring *spring = new Spring(from, down, springRL, springDamping, springStiffness);
                mFabric.addSpring(spring);
               // s.render();
            }
            
            if (x < numX-1) {
                Node *right = new Node(mFabric.nodes.at((x + 1)*numY + y)->mLoc);
                Spring *spring = new Spring(from, right, springRL, springDamping, springStiffness);
                mFabric.addSpring(spring);
            //    cout<< from.mLoc << " " << right.mLoc << endl;
            }
        }
    }
    
}

void FabricTerrainApp::mouseDown( MouseEvent event )
{
}

void FabricTerrainApp::update()
{
    mFabric.update();
}

void FabricTerrainApp::draw()
{
 //   gl::clear( Color( 0.15f, 0.15f, 0.15f ) );
    
    gl::pushMatrices();
    gl::translate(xPadding, yPadding, 0.);
    mFabric.render();
    gl::popMatrices();

}

void FabricTerrainApp::repel(Node *tempNode){
   // vec3 diff = to->mLoc - from->mLoc;

}

CINDER_APP( FabricTerrainApp, RendererGl, &FabricTerrainApp::prepareSettings)
