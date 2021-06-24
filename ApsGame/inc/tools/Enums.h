#ifndef ENUMS_H
#define ENUMS_H
/**
 * @brief The Request enum
 */
enum class Request
{
    CONNECT = 0,
    SIGNUP,
    LOGIN_STATE,
    CHANGE_ACCOUNT,
    GLOBAL_SCORE,
    PERSONAL_SCORE,
    SAVE_SCORE,
    DISCONNECT
};
#endif // ENUMS_H
