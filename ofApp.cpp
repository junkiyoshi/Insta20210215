#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39, 39, 239);
	ofSetColor(0);

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	int span = 5;
	for (int x = 0; x < ofGetWidth(); x += span) {

		for (int y = 0; y < ofGetHeight(); y += span) {

			auto noise_value = ofNoise(x * 0.0025, y * 0.0025 + ofGetFrameNum() * 0.005, ofGetFrameNum() * 0.005);

			if (noise_value < 0.85) {

				this->mesh.addVertex(glm::vec3(x, y, 0));
				this->mesh.addVertex(glm::vec3(x + span, y, 0));
				this->mesh.addVertex(glm::vec3(x + span, y + span, 0));
				this->mesh.addVertex(glm::vec3(x, y + span, 0));

				this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 4); this->mesh.addIndex(this->mesh.getNumVertices() - 3);
				this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 2); this->mesh.addIndex(this->mesh.getNumVertices() - 3);

				auto alpha = ofMap(noise_value, 0, 0.85, 255, 0);
				for (int i = 0; i < 4; i++) { this->mesh.addColor(ofColor(239, alpha)); }
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->mesh.draw();

	string word = "PCD 2021";
	this->font.drawStringAsShapes(word, ofGetWidth() * 0.5 + this->font.stringWidth(word) * -0.5, ofGetHeight() * 0.5 + this->font.stringHeight(word) * 0.5);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}