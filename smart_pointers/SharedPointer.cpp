#include <string>
#include <iostream>

class Project {
private:
	std::string prj_Name;
public:
	void SetProjectName(const std::string prj_Name) {
		this->prj_Name = prj_Name;
	}
	void GetProjectName() const{
		std::cout << "[Project Name]: " << prj_Name << std::endl;
	}
};

class Employee {
private:
	std::shared_ptr<Project> emp_Prj{};
public:
	void SetEmpProject(std::shared_ptr<Project> &prj) {
		emp_Prj = prj;
	}
	const std::shared_ptr<Project>& GetEmpProject() const{
		return emp_Prj;
	}
};