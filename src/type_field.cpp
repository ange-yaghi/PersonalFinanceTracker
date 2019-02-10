#include "type_field.h"
#include <database_layer.h>

pft::TypeField::TypeField() {
    m_hasValue = false;
}

pft::TypeField::~TypeField() {}

bool pft::TypeField::SetUserSearch(std::string &search) {
    FieldInput::SetUserSearch(search);
    m_database->GetAllTypeSuggestions(search.c_str(), this);

    return true;
}

void pft::TypeField::UseSuggestion(int n) {
    m_hasValue = true;
    m_currentValue = *m_suggestions[n];
}
