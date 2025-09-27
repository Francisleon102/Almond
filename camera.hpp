#ifndef CAMERA_HPP
#define CAMERA_HPP

// camera.hpp
// Description: Camera class declaration

class Camera {
public:
    Camera();
    ~Camera();

    // Copy constructor and assignment
    Camera(const Camera& other);
    Camera& operator=(const Camera& other);

    // Move constructor and assignment
    Camera(Camera&& other) noexcept;
    Camera& operator=(Camera&& other) noexcept;



private:
    // Private member variables
    // e.g., int width_;
    //       int height_;
};
 void initialize();
    void capture();
    void shutdown();
#endif // CAMERA_HPP