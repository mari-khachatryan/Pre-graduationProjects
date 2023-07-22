#ifndef PRECONDVIOLATEDEXCEP_H
#define PRECONDVIOLATEDEXCEP_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error {
public:
    explicit PrecondViolatedExcep(const std::string& message = "")
        : std::logic_error("Precondition Violated Exception: " + message) {}
};

#endif  // PRECONDVIOLATEDEXCEP_H