#ifndef DEF_COMMUNICATIVEOBJECT
#define DEF_COMMUNICATIVEOBJECT

#include <string>

/** 
* @class CommunicativeObject
*
* @brief The more abstract class able to send messages and communicate via the Plugin System messages.
* 
* @author Gwenael Pluchon
* 
*/
class CommunicativeObject
{
public:
	CommunicativeObject(std::string name);
	CommunicativeObject();
	~CommunicativeObject();

	/**	
	* name getter
	* @return the name of the CommunicativeObject
	*/

	std::string getName();
private:
	std::string _name;
};

#endif /* DEF_COMMUNICATIVEOBJECT */
