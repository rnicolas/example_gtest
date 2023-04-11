#ifndef __STATUS_HPP__
#define __STATUS_HPP__


namespace math {
	enum class StatusCode {
		OK,
		UNKNOWN,
		INTERNAL,
		UNIMPLEMENTED,
		INVALID_STATE,
		TIMEOUT,
		UNAVAILABLE,
		INVALID_ARGUMENT,
		NOT_FOUND,
		ALREADY_EXISTS,
	};

	class Status {
		private:
		StatusCode statusCode;

		public:
		Status(StatusCode statusCode);

		StatusCode status();
		bool ok();
	};

	template<typename T> class StatusOr: public Status {
		private:
		T val;

		public:
		StatusOr(StatusCode statusCode);
		StatusOr(T value);
		StatusOr(StatusCode statusCode, T value);

		T value();
	};

	template<typename T> inline StatusOr<T>::StatusOr(StatusCode statusCode): Status(statusCode) {}

	template<typename T> inline StatusOr<T>::StatusOr(T value): Status(StatusCode::OK), val(value) {}

	template<typename T> inline StatusOr<T>::StatusOr(StatusCode statusCode, T value): Status(statusCode), val(value) {}

	template<typename T> inline T StatusOr<T>::value() { return val; }
}; // namespace math

#endif //__STATUS_HPP__
