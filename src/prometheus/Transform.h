#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Component.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
namespace prometheus
{
	/// Transform manages rotation and position in space.
	/// Holds information about local rotation and position, as well as calculating model matrix.
	/// Provides access and manipulation functions for easily changing object locations.
	class Transform : public Component
	{
	public:
		/// Constructor for transform.
		/// Sets localPosition and localRotation to 0 and creates model matrix.
		Transform();
		~Transform();

		/// Translates local position by given amount in parameter.
		/// Translation matrix is build from input vector and multiplied by position matrix.
		/// @params [in] amount Vector showing amount to be translated in each axis.
		/// @params [out] localPosition Updated local position using translation matrix.
		void Translate(glm::vec3 amount);

		/// Scales model coordinates by given amounts in parameter.
		/// Scaling matrix created and applied to localScale variable.
		/// @param [in] amount Vector giving scalar amount each axis.
		/// @param [out] localScale Update local scale using scaling matrix.
		void Scale(glm::vec3 amount);

		/// Rotates transform by given angle around given axis.
		/// Rotation matrix created from axis and rotation angle.
		/// New model matrix created from translation matrix and rotation matrix.
		/// @param angle Angle to be added to rotation.
		/// @param axis Axis of rotation angle will be added to.
		void Rotate(float angle, glm::vec3 axis);

		/// Sets local from vec3 input.
		/// Transform::localPosition is set to input parameter position.
		/// The transformations are then applied in Transform::ApplyTransformation()
		/// @param position New local position.
		void SetLocalPosition(glm::vec3 position);

		/// Sets local position from three floats.
		/// Transform::localPosition is set to input coordinates.
		/// Transformations are then applied in Transform::ApplyTransformation()
		/// @param x, y, z The new x, y and z position coordinates.
		void SetLocalPosition(float x, float y, float z);

		/// Sets local rotation from vec3 input.
		/// Transform::localRotation is set to input coordinates.
		/// Transformations are then applied to get updated model matrix.
		/// @param rotation New local rotation.
		void SetLocalRotation(glm::vec3 rotation);

		/// Sets local rotation from three floats.
		/// Transforms::localRotation is set to input coordinates.
		/// Transformations are then applied to updated model matrix.
		/// @param x,y,z New z, y and z rotation values.
		void SetLocalRotation(float x, float y, float z);

		/// Sets local scale from vec3 input.
		/// Transforms::localScale is set to input vector.
		/// Transformations are then applied to update model matrix.
		/// @param scale New localSale.
		void SetLocalScale(glm::vec3 scale);

		/// Recalculates model matrix.
		/// Uses the translation and rotation matrix to generate new model matrix.
		/// @params [out] modelMatrix New model matrix generated.
		void ApplyTransformations();

		/// Adds difference to localPosition.
		/// Adds difference vector to localPosition vector to move object.
		/// @param difference Change in local position.
		void Move(glm::vec3 difference);

		/// Adds rotation to localRotation.
		/// Adds amount parameter to localRotation.
		/// @param [out] localRotation Change in local rotation by amount parameter.
		void AddRotation(glm::vec3 amount);

		/// Get model matrix.
		/// Returns mat4 model matrix of object.
		/// @returns Entity model matrix.
		glm::mat4 GetModelMatrix();

		/// Get local position.
		/// Returns vec3 local position of object.
		/// @returns Entity local position.
		glm::vec3 GetLocalPosition();

		/// Get local rotation.
		/// Returns vec3 local rotation of object.
		/// @returns Entity local rotation
		glm::vec3 GetLocalRotation();
	private:
		/// Local position of transform.
		glm::vec3 localPosition;
		/// Local rotation of transform.
		glm::vec3 localRotation;
		/// Local scale of transform.
		glm::vec3 localScale;
		/// Model matrix.
		glm::mat4 modelMatrix;
	};
}
#endif // !TRANSFORM_H_
