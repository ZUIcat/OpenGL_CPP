#pragma once

class GLDrawble {
  private:
  public:
    // GLDrawble();
    virtual ~GLDrawble() = default;

    virtual bool InitShader() = 0;
    virtual bool InitData() = 0;
    virtual void DrawSelf() = 0;
    virtual void Delete() = 0;
};
