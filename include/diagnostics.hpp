#include <vector>
#include <string>


//TODO: add other necessary methods for BuildLog
class BuildLog
{
private:
  size_t error_count = 0;
  std::vector<std::string> messages;
public:
  //for errors that cannot be traced to a single line
  //'Global error: <error message goes here>'
  void log_error(std::string error_message);

  //for regular errors: 
  //'In line x: <error message goes here>' 
  void log_error(std::string error_message, size_t line_index);
};
