#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include <QStyle>
#include <QRegularExpression>
#include <memory>
#include <iostream>
#include <mutex>

/**
 * @brief rePolish 刷新qss
 */
extern std::function<void(QWidget*)>rePolish;

#endif // GLOBAL_H
