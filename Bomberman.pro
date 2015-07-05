#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T14:24:31
#
#-------------------------------------------------

QT       += core gui uitools
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia


TARGET = ../bomberman

TEMPLATE = app


SOURCES += \
    classes/sources/AObj.cpp \
    classes/sources/AObjFactory.cpp \
    classes/sources/AssetsManager.cpp \
    classes/sources/Board.cpp \
    classes/sources/Bomb.cpp \
    classes/sources/SkyBox.cpp \
    classes/sources/GameOver.cpp \
    classes/sources/BombLvlBonus.cpp \
    classes/sources/BombNbBonus.cpp \
    classes/sources/BonusEngine.cpp \
    classes/sources/Camera.cpp \
    classes/sources/CubeColor.cpp \
    classes/sources/Explosion.cpp \
    classes/sources/GameEngine.cpp \
    classes/sources/IA.cpp \
    classes/sources/Limit.cpp \
    classes/sources/MapConstructor.cpp \
    classes/sources/Obstacle.cpp \
    classes/sources/Options.cpp \
    classes/sources/Player.cpp \
    classes/sources/SpeedBonus.cpp \
    classes/sources/SpeedMalus.cpp \
    classes/sources/Wall.cpp \
    classes/sources/Way.cpp \
    menu/highscoremenu.cpp \
    menu/loadmenu.cpp \
    menu/main.cpp \
    menu/menu.cpp \
    menu/newgamemenu.cpp \
    menu/Param.cpp

HEADERS  += \
    classes/includes/AObj.hh \
    classes/includes/AObjFactory.hh \
    classes/includes/AssetsManager.hh \
    classes/includes/Board.hh \
    classes/includes/Bomb.hh \
    classes/includes/BombLvlBonus.hh \
    classes/includes/BombNbBonus.hh \
    classes/includes/BonusEngine.hh \
    classes/includes/Camera.hh \
    classes/includes/SkyBox.hh \
    classes/includes/GameOver.hh \
    classes/includes/Cube.hpp \
    classes/includes/CubeColor.hh \
    classes/includes/Exceptions.hpp \
    classes/includes/Explosion.hh \
    classes/includes/GameEngine.hh \
    classes/includes/IA.hh \
    classes/includes/IIA.hh \
    classes/includes/IMapConstructor.hh \
    classes/includes/Limit.hh \
    classes/includes/MapConstructor.hh \
    classes/includes/Obstacle.hh \
    classes/includes/Options.hh \
    classes/includes/Player.hh \
    classes/includes/SpeedBonus.hh \
    classes/includes/SpeedMalus.hh \
    classes/includes/Wall.hh \
    classes/includes/Way.hh \
    libgdl/includes/GL/glew.h \
    libgdl/includes/GL/glxew.h \
    libgdl/includes/GL/wglew.h \
    libgdl/includes/glm/core/_detail.hpp \
    libgdl/includes/glm/core/_fixes.hpp \
    libgdl/includes/glm/core/_swizzle.hpp \
    libgdl/includes/glm/core/_swizzle_func.hpp \
    libgdl/includes/glm/core/_vectorize.hpp \
    libgdl/includes/glm/core/func_common.hpp \
    libgdl/includes/glm/core/func_exponential.hpp \
    libgdl/includes/glm/core/func_geometric.hpp \
    libgdl/includes/glm/core/func_integer.hpp \
    libgdl/includes/glm/core/func_matrix.hpp \
    libgdl/includes/glm/core/func_noise.hpp \
    libgdl/includes/glm/core/func_packing.hpp \
    libgdl/includes/glm/core/func_trigonometric.hpp \
    libgdl/includes/glm/core/func_vector_relational.hpp \
    libgdl/includes/glm/core/hint.hpp \
    libgdl/includes/glm/core/intrinsic_common.hpp \
    libgdl/includes/glm/core/intrinsic_exponential.hpp \
    libgdl/includes/glm/core/intrinsic_geometric.hpp \
    libgdl/includes/glm/core/intrinsic_matrix.hpp \
    libgdl/includes/glm/core/intrinsic_trigonometric.hpp \
    libgdl/includes/glm/core/intrinsic_vector_relational.hpp \
    libgdl/includes/glm/core/setup.hpp \
    libgdl/includes/glm/core/type.hpp \
    libgdl/includes/glm/core/type_float.hpp \
    libgdl/includes/glm/core/type_gentype.hpp \
    libgdl/includes/glm/core/type_half.hpp \
    libgdl/includes/glm/core/type_int.hpp \
    libgdl/includes/glm/core/type_mat.hpp \
    libgdl/includes/glm/core/type_mat2x2.hpp \
    libgdl/includes/glm/core/type_mat2x3.hpp \
    libgdl/includes/glm/core/type_mat2x4.hpp \
    libgdl/includes/glm/core/type_mat3x2.hpp \
    libgdl/includes/glm/core/type_mat3x3.hpp \
    libgdl/includes/glm/core/type_mat3x4.hpp \
    libgdl/includes/glm/core/type_mat4x2.hpp \
    libgdl/includes/glm/core/type_mat4x3.hpp \
    libgdl/includes/glm/core/type_mat4x4.hpp \
    libgdl/includes/glm/core/type_size.hpp \
    libgdl/includes/glm/core/type_vec.hpp \
    libgdl/includes/glm/core/type_vec1.hpp \
    libgdl/includes/glm/core/type_vec2.hpp \
    libgdl/includes/glm/core/type_vec3.hpp \
    libgdl/includes/glm/core/type_vec4.hpp \
    libgdl/includes/glm/gtc/constants.hpp \
    libgdl/includes/glm/gtc/epsilon.hpp \
    libgdl/includes/glm/gtc/half_float.hpp \
    libgdl/includes/glm/gtc/matrix_access.hpp \
    libgdl/includes/glm/gtc/matrix_integer.hpp \
    libgdl/includes/glm/gtc/matrix_inverse.hpp \
    libgdl/includes/glm/gtc/matrix_transform.hpp \
    libgdl/includes/glm/gtc/noise.hpp \
    libgdl/includes/glm/gtc/quaternion.hpp \
    libgdl/includes/glm/gtc/random.hpp \
    libgdl/includes/glm/gtc/reciprocal.hpp \
    libgdl/includes/glm/gtc/swizzle.hpp \
    libgdl/includes/glm/gtc/type_precision.hpp \
    libgdl/includes/glm/gtc/type_ptr.hpp \
    libgdl/includes/glm/gtc/ulp.hpp \
    libgdl/includes/glm/gtx/associated_min_max.hpp \
    libgdl/includes/glm/gtx/bit.hpp \
    libgdl/includes/glm/gtx/closest_point.hpp \
    libgdl/includes/glm/gtx/color_cast.hpp \
    libgdl/includes/glm/gtx/color_space.hpp \
    libgdl/includes/glm/gtx/color_space_YCoCg.hpp \
    libgdl/includes/glm/gtx/compatibility.hpp \
    libgdl/includes/glm/gtx/component_wise.hpp \
    libgdl/includes/glm/gtx/constants.hpp \
    libgdl/includes/glm/gtx/epsilon.hpp \
    libgdl/includes/glm/gtx/euler_angles.hpp \
    libgdl/includes/glm/gtx/extend.hpp \
    libgdl/includes/glm/gtx/extented_min_max.hpp \
    libgdl/includes/glm/gtx/fast_exponential.hpp \
    libgdl/includes/glm/gtx/fast_square_root.hpp \
    libgdl/includes/glm/gtx/fast_trigonometry.hpp \
    libgdl/includes/glm/gtx/gradient_paint.hpp \
    libgdl/includes/glm/gtx/handed_coordinate_space.hpp \
    libgdl/includes/glm/gtx/inertia.hpp \
    libgdl/includes/glm/gtx/int_10_10_10_2.hpp \
    libgdl/includes/glm/gtx/integer.hpp \
    libgdl/includes/glm/gtx/intersect.hpp \
    libgdl/includes/glm/gtx/log_base.hpp \
    libgdl/includes/glm/gtx/matrix_cross_product.hpp \
    libgdl/includes/glm/gtx/matrix_interpolation.hpp \
    libgdl/includes/glm/gtx/matrix_major_storage.hpp \
    libgdl/includes/glm/gtx/matrix_operation.hpp \
    libgdl/includes/glm/gtx/matrix_query.hpp \
    libgdl/includes/glm/gtx/mixed_product.hpp \
    libgdl/includes/glm/gtx/multiple.hpp \
    libgdl/includes/glm/gtx/noise.hpp \
    libgdl/includes/glm/gtx/norm.hpp \
    libgdl/includes/glm/gtx/normal.hpp \
    libgdl/includes/glm/gtx/normalize_dot.hpp \
    libgdl/includes/glm/gtx/number_precision.hpp \
    libgdl/includes/glm/gtx/ocl_type.hpp \
    libgdl/includes/glm/gtx/optimum_pow.hpp \
    libgdl/includes/glm/gtx/orthonormalize.hpp \
    libgdl/includes/glm/gtx/perpendicular.hpp \
    libgdl/includes/glm/gtx/polar_coordinates.hpp \
    libgdl/includes/glm/gtx/projection.hpp \
    libgdl/includes/glm/gtx/quaternion.hpp \
    libgdl/includes/glm/gtx/random.hpp \
    libgdl/includes/glm/gtx/raw_data.hpp \
    libgdl/includes/glm/gtx/reciprocal.hpp \
    libgdl/includes/glm/gtx/rotate_vector.hpp \
    libgdl/includes/glm/gtx/simd_mat4.hpp \
    libgdl/includes/glm/gtx/simd_vec4.hpp \
    libgdl/includes/glm/gtx/spline.hpp \
    libgdl/includes/glm/gtx/std_based_type.hpp \
    libgdl/includes/glm/gtx/string_cast.hpp \
    libgdl/includes/glm/gtx/transform.hpp \
    libgdl/includes/glm/gtx/transform2.hpp \
    libgdl/includes/glm/gtx/ulp.hpp \
    libgdl/includes/glm/gtx/unsigned_int.hpp \
    libgdl/includes/glm/gtx/vec1.hpp \
    libgdl/includes/glm/gtx/vector_access.hpp \
    libgdl/includes/glm/gtx/vector_angle.hpp \
    libgdl/includes/glm/gtx/vector_query.hpp \
    libgdl/includes/glm/gtx/verbose_operator.hpp \
    libgdl/includes/glm/gtx/wrap.hpp \
    libgdl/includes/glm/virtrev/xstream.hpp \
    libgdl/includes/glm/ext.hpp \
    libgdl/includes/glm/glm.hpp \
    libgdl/includes/AShader.hh \
    libgdl/includes/Attribute.hh \
    libgdl/includes/BasicShader.hh \
    libgdl/includes/begin_code.h \
    libgdl/includes/Clock.hh \
    libgdl/includes/close_code.h \
    libgdl/includes/Game.hh \
    libgdl/includes/Geometry.hh \
    libgdl/includes/Input.hh \
    libgdl/includes/IRenderContext.hh \
    libgdl/includes/Model.hh \
    libgdl/includes/OpenGL.hh \
    libgdl/includes/SDL.h \
    libgdl/includes/SDL_assert.h \
    libgdl/includes/SDL_atomic.h \
    libgdl/includes/SDL_audio.h \
    libgdl/includes/SDL_bits.h \
    libgdl/includes/SDL_blendmode.h \
    libgdl/includes/SDL_clipboard.h \
    libgdl/includes/SDL_config.h \
    libgdl/includes/SDL_config_android.h \
    libgdl/includes/SDL_config_iphoneos.h \
    libgdl/includes/SDL_config_macosx.h \
    libgdl/includes/SDL_config_minimal.h \
    libgdl/includes/SDL_config_pandora.h \
    libgdl/includes/SDL_config_psp.h \
    libgdl/includes/SDL_config_windows.h \
    libgdl/includes/SDL_config_winrt.h \
    libgdl/includes/SDL_config_wiz.h \
    libgdl/includes/SDL_copying.h \
    libgdl/includes/SDL_cpuinfo.h \
    libgdl/includes/SDL_egl.h \
    libgdl/includes/SDL_endian.h \
    libgdl/includes/SDL_error.h \
    libgdl/includes/SDL_events.h \
    libgdl/includes/SDL_filesystem.h \
    libgdl/includes/SDL_gamecontroller.h \
    libgdl/includes/SDL_gesture.h \
    libgdl/includes/SDL_haptic.h \
    libgdl/includes/SDL_hints.h \
    libgdl/includes/SDL_joystick.h \
    libgdl/includes/SDL_keyboard.h \
    libgdl/includes/SDL_keycode.h \
    libgdl/includes/SDL_loadso.h \
    libgdl/includes/SDL_log.h \
    libgdl/includes/SDL_main.h \
    libgdl/includes/SDL_messagebox.h \
    libgdl/includes/SDL_mouse.h \
    libgdl/includes/SDL_mutex.h \
    libgdl/includes/SDL_name.h \
    libgdl/includes/SDL_opengl.h \
    libgdl/includes/SDL_opengles.h \
    libgdl/includes/SDL_opengles2.h \
    libgdl/includes/SDL_pixels.h \
    libgdl/includes/SDL_platform.h \
    libgdl/includes/SDL_power.h \
    libgdl/includes/SDL_quit.h \
    libgdl/includes/SDL_rect.h \
    libgdl/includes/SDL_render.h \
    libgdl/includes/SDL_revision.h \
    libgdl/includes/SDL_rwops.h \
    libgdl/includes/SDL_scancode.h \
    libgdl/includes/SDL_shape.h \
    libgdl/includes/SDL_stdinc.h \
    libgdl/includes/SDL_surface.h \
    libgdl/includes/SDL_system.h \
    libgdl/includes/SDL_syswm.h \
    libgdl/includes/SDL_test.h \
    libgdl/includes/SDL_test_assert.h \
    libgdl/includes/SDL_test_common.h \
    libgdl/includes/SDL_test_compare.h \
    libgdl/includes/SDL_test_crc32.h \
    libgdl/includes/SDL_test_font.h \
    libgdl/includes/SDL_test_fuzzer.h \
    libgdl/includes/SDL_test_harness.h \
    libgdl/includes/SDL_test_images.h \
    libgdl/includes/SDL_test_log.h \
    libgdl/includes/SDL_test_md5.h \
    libgdl/includes/SDL_test_random.h \
    libgdl/includes/SDL_thread.h \
    libgdl/includes/SDL_timer.h \
    libgdl/includes/SDL_touch.h \
    libgdl/includes/SDL_types.h \
    libgdl/includes/SDL_version.h \
    libgdl/includes/SDL_video.h \
    libgdl/includes/SdlContext.hh \
    libgdl/includes/Texture.hh \
    libgdl/src/BasicShader.hh \
    menu/highscoremenu.h \
    menu/loadmenu.h \
    menu/menu.h \
    menu/newgamemenu.h \
    menu/Param.h

FORMS    += \
    menu/loadmenu.ui \
    menu/highscoremenu.ui \
    menu/menu.ui \
    menu/newgamemenu.ui
    
ICON = /iconMenu/bomber.ico

LIBS = -L ../libgdl/libs/ -lm -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -ldl -lpthread

INCLUDEPATH = ./classes/includes/ ./core/includes/ ./libgdl/includes/

DISTFILES +=
