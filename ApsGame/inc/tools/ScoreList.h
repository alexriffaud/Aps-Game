#ifndef SCORELIST_H
#define SCORELIST_H

#include <QAbstractListModel>
#include <QVector>

#include "Score.h"

/**
 * @brief The ScoreList class
 */
class ScoreList : public QAbstractListModel
{
    Q_OBJECT
public:
    /**
     * @brief rowCount
     * @return
     */
    int rowCount(const QModelIndex&) const override;
    /**
     * @brief data
     * @param index
     * @param role
     * @return
     */
    QVariant data(const QModelIndex& index, int role) const override;

    /**
     * @brief findObject
     * @param id
     * @return
     */
    QObject * findObject(int id);

    /**
     * @brief items
     * @return
     */
    QVector<QObject *> *items();

public slots:
    /**
     * @brief insert
     * @param item
     */
    void insert(QObject* item);
    /**
     * @brief remove
     * @param item
     */
    void remove(QObject* item);
    /**
     * @brief removeAll
     */
    void removeAll();
    /**
     * @brief updateItem
     * @param score
     */
    void updateItem(Score *score);
    /**
     * @brief clear
     */
    void clear();
    /**
     * @brief size
     * @return
     */
    int size();
    /**
     * @brief at
     * @param index
     * @return
     */
    QObject * at(int index);


protected:
    /**
     * @brief roleNames
     * @return
     */
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<QObject*> _items;  /*!< Container for Score */
};

#endif // SCORELIST_H
