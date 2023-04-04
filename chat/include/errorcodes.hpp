#ifndef ERRORCODES_HPP_
#define ERRORCODES_HPP_

class ErrorMessage
{
public:
	const std::string connection_error = "Connection failed";		

	const std::string listening_error = "Time is up";

	const std::string upnp_failed = "UPNP is not supported on your router or is off";

public:
	ErrorMessage() = default;
	~ErrorMessage() = default;
};

#endif /* ERRORCODES_HPP_ */
