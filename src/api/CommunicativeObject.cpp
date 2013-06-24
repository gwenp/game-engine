#include "CommunicativeObject.hpp"

CommunicativeObject::CommunicativeObject(std::string name): _name(name){}
CommunicativeObject::CommunicativeObject():_name("CommunicativeObject"){}
CommunicativeObject::~CommunicativeObject(){}

std::string CommunicativeObject::getName(){ return _name;}
