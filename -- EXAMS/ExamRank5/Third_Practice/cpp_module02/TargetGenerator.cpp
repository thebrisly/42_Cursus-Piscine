#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() 
{ }

TargetGenerator::~TargetGenerator() 
{ 
    std::map<std::string, ATarget *>::iterator it_begin = this->arr.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->arr.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->arr.clear();
}

void TargetGenerator::learnTargetType(ATarget *atarget_ptr)
{
    if (atarget_ptr)
        arr.insert(std::pair<std::string, ATarget *>(atarget_ptr->getType(), atarget_ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
    arr.erase(name);
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
    std::map<std::string, ATarget *>::iterator it = arr.find(name);
    if (it != arr.end())
        return (arr[name]);
    return NULL;
}