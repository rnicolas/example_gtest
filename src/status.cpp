#include "status.hpp"

math::Status::Status(StatusCode statusCode): statusCode(statusCode) {}

math::StatusCode math::Status::status()
{
	return statusCode;
}

bool math::Status::ok()
{
	return statusCode == StatusCode::OK;
}
