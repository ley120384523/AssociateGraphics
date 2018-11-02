#include "AnchorPoint.h"
#include <QPainter>


AnchorPoint::AnchorPoint(QGraphicsItem* parent)
	:QGraphicsObject(parent)
{
	setFlag(QGraphicsItem::ItemHasNoContents, true);		// ʹpaint��Ч
	setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);	// ����λ�øı��ź�
	setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);	// ����λ�øı��ź�
}

QRectF AnchorPoint::boundingRect() const
{
	return QRectF();
}

void AnchorPoint::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
}

QVariant AnchorPoint::itemChange(GraphicsItemChange change, const QVariant& value)
{
	if (change == QGraphicsItem::ItemPositionChange)
	{
		emit positionChanged(value.toPointF());
	}
	else if (change == QGraphicsItem::ItemScenePositionHasChanged)
	{
		emit positionChanged(value.toPointF());
	}

	return QGraphicsObject::itemChange(change, value);
}
