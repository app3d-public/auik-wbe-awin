# Auik Awin Window Backend

`auik-wbe-awin` is the Awin window backend for [Auik](../auik).
It connects Auik host-window services to an Awin window.

## Building

`auik-wbe-awin` is distributed as a CMake module and is intended to be added after `auik` and `awin`.

Example:

```cmake
add_subdirectory(modules/auik)
add_subdirectory(modules/awin)
add_subdirectory(modules/auik-wbe-awin)
```

## Usage

Create an Auik window backend from an Awin window:

```cpp
auto *window_backend = auik::create_awin_backend(window, event_dispatcher);
```

Pass it to Auik through `auik::CreateInfo::set_window_backend()`.

## Dependencies

- [auik](../auik)
- [awin](../awin)
- [acul](../acul)

## License
This project is licensed under the [MIT License](LICENSE).

## Contacts
For any questions or feedback, you can reach out via [email](mailto:wusikijeronii@gmail.com) or open a new issue.

