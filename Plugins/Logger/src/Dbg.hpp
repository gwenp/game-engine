#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <string>
#include <vector>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <iostream>

#include <algorithm>
  
class Dbg
{
public:
	static void init(std::string configFile)
	{
		std::ifstream ifs(configFile.c_str());

		Json::Value root; // will contains the root value after parsing.
		Json::Reader reader;
		bool parsingSuccessful = reader.parse( ifs, root );
		if ( !parsingSuccessful )
		{
			// report to the user the failure and their locations in the document.
			std::cout << "Failed to parse configuration\n"
				<< reader.getFormattedErrorMessages();
			return;
		}
	
		const Json::Value print = root["print"];
		for ( int index = 0; index < print.size(); ++index ) // Iterates over the sequence elements.
		{
			// out.addVerboseCategory(print[index].asString() );
			Dbg::_printCategories.push_back(print[index].asString());
		
		}
	};

    static std::string _activeCategory;
    static std::vector<std::string> _printCategories;

	class Out {
		public:
			Out& operator ()(std::string category)
			{
				Dbg::_activeCategory = category;
				return *this;
			};

		template< typename T >
		friend Out& operator<<( Out& out, const T& obj)
		{
			if (std::find(Dbg::_printCategories.begin(), Dbg::_printCategories.end(), Dbg::_activeCategory) != Dbg::_printCategories.end())
			{
				std::cout << obj;
			}
			return out;
		};
	
		friend Out& operator<<( Out& out, std::ostream& (*manip)(std::ostream&) )
		{
			if (std::find(Dbg::_printCategories.begin(), Dbg::_printCategories.end(), Dbg::_activeCategory) != Dbg::_printCategories.end())
			{
				std::cout << manip;
			}
			return out;
		};
	};
	
	static Out out;
};	

#endif /* DEBUG_HPP */