#ifndef RECTANLGE_H
#define RECTANLGE_H

#include "Core/Public/Common/Common.h"
#include "Core/Public/Algorithm/GeneralUtilities.h"

namespace Forge {
	namespace Math
	{
		/**
		 * @brief A 2D Rectangle defined by X and Y position, width and height.
		 * 
		 * @author Karim Hisham.
		 */
		template<typename InType, 
				 typename = typename Common::TEnableIf<Common::TIsArithmetic<InType>::Value, InType>::Type>
		class TRectangle
		{
		private:
			InType m_x, m_y;
			InType m_width, m_height;

		public:
			/**
			 * @brief Default Constructor.
			 * 
			 * Constructs a rectangle with zero dimensions.
			 */
			TRectangle(Void)
				: m_x(0), m_y(0), m_width(0), m_height(0) {}

			/**
			 * @brief Constructor.
			 *
			 * Constructs a rectangle with x, y, width and height values.
			 */
			TRectangle(InType x, InType y, InType width, InType height)
				: m_x(x), m_y(y), m_width(width), m_height(height) {}

			/**
			 * @brief Constructor.
			 *
			 * Constructs a rectangle with position and size vectors.
			 */
			TRectangle(const Vector2& position, const Vector2& size)
				: m_x(position.m_first), m_y(position.m_second), m_width(size.m_first), m_height(size.m_second) {}

		public:
			/**
			 * @brief Move Assignment Operator.
			 */
			TRectangle<InType>& operator =(TRectangle<InType>&& other) = default;

			/**
			 * @brief Copy Assignment Operator.
			 */
			TRectangle<InType>& operator =(const TRectangle<InType>& other) = default;

		public:
			/**
			 * @brief Addition Operator.
			 * 
			 * This function offsets the rectangle position by the specified value.
			 */
			TRectangle<InType> operator +(InType value)
			{
				return { m_x + value, m_y + value, m_width, m_height };
			}

			/**
			 * @brief Subtraction Operator.
			 *
			 * This function offsets the rectangle position by the specified value.
			 */
			TRectangle<InType> operator -(InType value)
			{
				return { m_x - value, m_y - value, m_width, m_height };
			}

			/**
			 * @brief Multiplication Operator.
			 *
			 * This function scales the rectangle position and size by the
			 * specified value.
			 */
			TRectangle<InType> operator *(InType value)
			{
				return { m_x * value, m_y * value, m_width * value, m_height * value };
			}

			/**
			 * @brief Division Operator.
			 *
			 * This function scales the rectangle position and size by the
			 * specified value.
			 */
			TRectangle<InType> operator /(InType value)
			{
				return { m_x / value, m_y / value, m_width / value, m_height / value };
			}

			/**
			 * @brief Inplace Addition Operator.
			 *
			 * This function offsets the rectangle position by the specified value.
			 */
			TRectangle<InType> operator +=(InType value)
			{
				m_x += value; 
				m_y += value;
				
				return *this;
			}
			
			/**
			 * @brief Subtraction Operator.
			 *
			 * This function offsets the rectangle position by the specified value.
			 */
			TRectangle<InType> operator -=(InType value)
			{
				m_x -= value;
				m_y -= value;

				return *this;
			}
			
			/**
			 * @brief Multiplication Operator.
			 *
			 * This function scales the rectangle position and size by the
			 * specified value.
			 */
			TRectangle<InType> operator *=(InType value)
			{
				m_x *= value;
				m_y *= value;

				m_width *= value;
				m_height *= value;

				return *this;
			}
			
			/**
			 * @brief Division Operator.
			 *
			 * This function scales the rectangle position and size by the
			 * specified value.
			 */
			TRectangle<InType> operator /=(InType value)
			{
				m_x /= value;
				m_y /= value;

				m_width /= value;
				m_height /= value;

				return *this;
			}

		public:
			/**
			 * @brief Equality Operator.
			 */
			Bool operator ==(const TRectangle<InType>& other)
			{
				return m_x == other.m_x && m_y == other.m_y &&
					   m_width == other.m_width && m_height == other.m_height;
			}

			/**
			 * @brief Non-Equality Operator.
			 */
			Bool operator !=(const TRectangle<InType>& other)
			{
				return m_x != other.m_x && m_y != other.m_y &&
					   m_width != other.m_width && m_height != other.m_height;
			}

		public:
			/**
			 * @brief Gets the x coordinate of the top edge of the rectangle.
			 * 
			 * @returns InType storing the value of the rectangle's x coordinate.
			 */
			FORGE_FORCE_INLINE InType GetX(Void) 
			{ 
				return m_x; 
			}

			/**
			 * @brief Gets the y coordinate of the top edge of the rectangle.
			 *
			 * @returns InType storing the value of the rectangle's y coordinate.
			 */
			FORGE_FORCE_INLINE InType GetY(Void) 
			{ 
				return m_y; 
			}

			/**
			 * @brief Gets the width of the rectangle.
			 *
			 * @returns InType storing the value of the rectangle's width.
			 */
			FORGE_FORCE_INLINE InType GetWidth(Void) 
			{ 
				return m_width; 
			}

			/**
			 * @brief Gets the height of the rectangle.
			 *
			 * @returns InType storing the value of the rectangle's width.
			 */
			FORGE_FORCE_INLINE InType GetHeight(Void) 
			{ 
				return m_height; 
			}

		public:
			/**
			 * @brief Gets the size of the rectangle.
			 *
			 * @returns Vector2 storing the size of this rectangle.
			 */
			FORGE_FORCE_INLINE Vector2 GetSize(Void)
			{
				return { m_width, m_height };
			}

			/**
			 * @brief Gets the center point of the rectangle.
			 * 
			 * @returns Vector2 storing the center point of this rectangle.
			 */
			FORGE_FORCE_INLINE Vector2 GetCenter(Void) 
			{ 
				return { (m_x + (m_x + m_width)) / 2, (m_y + (m_y + m_height)) / 2 }; 
			}

			/**
			 * @brief Gets the extents of the rectangle.
			 * 
			 * This is always half of the size of the rectangle.
			 * 
			 * @returns Vector2 storing the extents of this rectangle.
			 */
			FORGE_FORCE_INLINE Vector2 GetExtents(Void) 
			{ 
				return { m_width / 2, m_height / 2 }; 
			}

			/**
			 * @brief Gets the top left point of the rectangle.
			 *
			 * @returns Vector2 storing the left point of this rectangle.
			 */
			FORGE_FORCE_INLINE Vector2 GetTopLeft(Void)
			{
				return { m_x, m_y };
			}

			/**
			 * @brief Gets the top right point of the rectangle.
			 *
			 * @returns Vector2 storing the right point point of this rectangle.
			 */
			FORGE_FORCE_INLINE Vector2 GetTopRight(Void)
			{
				return { m_x + m_width, m_y };
			}

			/**
			 * @brief Gets the bottom left point of the rectangle.
			 *
			 * @returns Vector2 storing the bottom left point of this rectangle.
			 */
			FORGE_FORCE_INLINE Vector2 GetBottomLeft(Void)
			{
				return { m_x, m_y + m_height };
			}

			/**
			 * @brief Gets the bottom right point of the rectangle.
			 *
			 * @returns Vector2 storing the bottom right point of this rectangle.
			 */
			FORGE_FORCE_INLINE Vector2 GetBottomRight(Void)
			{
				return { m_x + m_width, m_y + m_height };
			}

		public:
			/**
			 * @brief Merges a point with the rectangle.
			 * 
			 * @param point The point to merge with this rectangle.
			 */
			Void Merge(const Vector2& point)
			{
				m_x = Algorithm::Min(m_x, point.m_first);
				m_y = Algorithm::Min(m_y, point.m_second);
				
				m_width = Algorithm::Max(m_x + m_width, point.m_first) - m_x;
				m_height = Algorithm::Max(m_y + m_height, point.m_second) - m_y;
			}
			
			/**
			 * @brief Merges a rectangle with the rectangle.
			 *
			 //* @param rect The rectangle to merge with this rectangle.
			 */
			Void Merge(const TRectangle<InType>& rect)
			{
				m_x = Algorithm::Min(m_x, rect.m_x);
				m_y = Algorithm::Min(m_y, rect.m_y);

				m_width = Algorithm::Max(m_x + m_width, rect.m_x + rect.m_width) - m_x;
				m_height = Algorithm::Max(m_y + m_height, rect.m_y + rect.m_height) - m_y;
			}

			/**
			 * @brief Calculates the rectangle that is the union between two
			 * rectangles.
			 *
			 * @param rect The rectangle to calculate union with this rectangle.
			 */
			Void Union(const TRectangle<InType>& rect)
			{
				m_x = Algorithm::Max(m_x, rect.m_x);
				m_y = Algorithm::Max(m_y, rect.m_y);

				m_width = Algorithm::Min(m_x + m_width, rect.m_x + rect.m_width) - m_x;
				m_height = Algorithm::Min(m_y + m_height, rect.m_y + rect.m_height) - m_y;
			}

			/**
			 * @brief Tests wether a point intersects the rectangle.
			 * 
			 * @param point The point to test with this rectangle.
			 * 
			 * @returns True if the point intersects, otherwise false.
			 */
			Bool Contains(const Vector2& point)
			{
				if (m_x < point.m_first && m_x + m_width > point.m_first &&
					m_y < point.m_second && m_y + m_height > point.m_second)
					return true;
				else
					return false;
			}
			
			/**
			 * @brief Tests wether a rectangle contains the rectangle.
			 *
			 * @param rect The rectangle to test with this rectangle.
			 *
			 * @returns True if the rectangle contains, otherwise false.
			 */
			Bool Contains(const TRectangle<InType>& rect)
			{
				if (m_x < rect.m_x + rect.m_width && m_x + m_width > rect.m_x &&
					m_y < rect.m_y + rect.m_height && m_y + m_height > rect.m_y)
					return true;
				else
					return false;
			}
		};
	}
}

#endif
