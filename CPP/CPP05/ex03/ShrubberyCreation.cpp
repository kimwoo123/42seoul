#include "ShrubberyCreation.hpp"

ShrubberyCreation::ShrubberyCreation(): AForm("Unknown", 145, 137) {}

ShrubberyCreation::ShrubberyCreation(const std::string& name): AForm(name, 145, 137) {}

ShrubberyCreation::ShrubberyCreation(const ShrubberyCreation& s): AForm(s) {}

ShrubberyCreation& ShrubberyCreation::operator=(const ShrubberyCreation& s) {
	if (this != &s) {
		this->setSigned(s.getSigned());
		std::cout << "There are member variables of type const which may not be copied correctly.\n";
	}
	return *this;
}

ShrubberyCreation::~ShrubberyCreation(void) {}

const char* ShrubberyCreation::CannotOpenFileException::what() const throw() {
	return "Cannot open file.\n";
}

void ShrubberyCreation::execute(Bureaucrat const &executor) const {
	std::string fileName;
	std::ofstream writeFile;

	if (this->getSigned() == false)
		throw AForm::NoSignException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	fileName = executor.getName() + "_shrubbery";
	writeFile.open(fileName.c_str());
	if (writeFile.is_open() == false)
		throw ShrubberyCreation::CannotOpenFileException();

	std::string tree =	"      * \n"
						"     /.\\ \n"
						"    /o..\\ \n"
						"    /..o\\ \n"
						"   /.o..o\\ \n"
						"   /...o.\\ \n"
						"  /..o....\\ \n"
						"  ^^^[_]^^^  \n";

	writeFile.write(tree.c_str(), tree.size());
	writeFile.close();
}
