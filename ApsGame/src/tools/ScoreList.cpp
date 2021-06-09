#include "../../inc/tools/ScoreList.h"

int ScoreList::rowCount(const QModelIndex&) const
{
    return _items.size();
}

QVariant ScoreList::data(const QModelIndex& index, int /*role*/) const
{
    QObject* item = _items.at(index.row());
    return QVariant::fromValue(item);
}

void ScoreList::insert(QObject* item)
{
    beginInsertRows(QModelIndex(), 0, 0);
    _items.push_front(item);
    endInsertRows();
}

void ScoreList::remove(QObject* item)
{
    for (int i = 0; i < _items.size(); ++i)
    {
        if (_items.at(i) == item)
        {
            beginRemoveRows(QModelIndex(), i, i);
            _items.remove(i);
            endRemoveRows();
            break;
        }
    }
}

QHash<int, QByteArray> ScoreList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "item";
    return roles;
}

QVector<QObject *> *ScoreList::items()
{
    return &_items;
}

void ScoreList::updateEventItem(Score* score)
{
    int i = 0;
    for (i = 0; i < _items.size(); ++i)
    {
        Score *score2 = (Score *)_items.at(i);
        if (score2->ID() == score2->ID())
        {
            _items[i] = score;
            dataChanged(index(i), index(i));
            break;
        }
    }
}

QObject *ScoreList::findObject(int id)
{
    QObject *object = nullptr;
    for (int i = 0; i < _items.size(); ++i)
    {
        Score *score = (Score *)_items.at(i);
        if (score->ID() == id)
        {
            object = _items.at(i);
        }
    }
    return object;
}

void ScoreList::clear()
{
    for (int i = 0; i < _items.size(); i++)
    {
        beginRemoveRows(QModelIndex(), i, i);
        _items.remove(i);
        endRemoveRows();
    }
}

int ScoreList::size()
{
    int s = 0;
    for (int i = 0; i < _items.size(); i++)
    {
        s++;
    }
    return s;
}

QObject * ScoreList::at(int index)
{
    QObject *object = nullptr;
    for (int i = 0; i < _items.size(); i++)
    {
        if(index == i)
        {
            object = _items.at(i);
        }
    }
    return object;
}
