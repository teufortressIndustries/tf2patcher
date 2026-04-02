# TF2 patcher for full-colored decals

## Summary

This tool allows you to remove various restrictions when applying a decal to a decalable item in TF2.

In short, now you can apply fully-colored images to your Objectors, Flairs, Photo Badges and Clan Prides.

This is a April 2026 update of [tf2patcher](https://github.com/dborodin836/tf2patcher) that ports compatibility to Linux.

## Is it safe?

> [!CAUTION]  
> **USE AT YOU OWN RISK.**
>
> It is unlikely that this tool will be detected by VAC. **However:**
>
> - It may be a good idea to take a look at current active issues;
> - I recommend running TF2 in ``-insecure`` mode while you do this.
> - After running this tool, **be sure to close TF2**. You can then safely open it again. This is not strictly
    necessary, but it's best to clear all memory modifications before connecting to a secure server.

## How to use

### Windows

1. Download the latest release [here](https://github.com/yari-dog/tf2patcher/releases/latest);

2. Run tf2patcher and launch TF2 (or do it in reverse, the order does not matter. Linux shouldn't require sudo/doas);

3. Now try applying a decal to your item - the preview pane should show a fully-colored image;

4. **After you've applied your decal, close TF2 in order to remove any modifications caused by the patcher.**

## Building from source

Run `make TARGET=32` or `make TARGET=64`, depending on which architecture you want to build for.

C11-aware compiler is required.

## How does it work

What exactly gets patched:

- m_pFilterCombo->GetActiveItem() call gets changed to "mov eax, 1" (reg/imm32 form) - this forces an "Identity" filter
  no matter what the schema says;

- bDoBlendLayers conditional jump gets changed to an inconditional jump (this skips all blending code altogether). (this is a JLE > JMP patch on linux)

## Linux support?

This linux support was added by yari-dog. if you think it's swag you should call me a good boy.

## License

See UNLICENSE file.
